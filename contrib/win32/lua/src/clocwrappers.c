#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#if defined(__APPLE__)
# include <xlocale.h>
#elif defined(_WIN32)
# include <windows.h>
# include <locale.h>
#else
# define _GNU_SOURCE
# include <locale.h>
#endif

/* A strtof replacement that always uses the C locale to ensure
 * it always accepts '.' as decimal point.
 */

#if defined(__APPLE__)

float strtof_c_locale(const char *nptr, char **endptr)
{
	return strtof_l(nptr, endptr, LC_C_LOCALE);
}

int snprintf_c_locale(char * restrict str, size_t size, const char * restrict format, ...)
{
	int res;
	va_list args;

    va_start(args, format);
	res = vsnprintf_l(str, size, LC_C_LOCALE, format, args);
	va_end(args);

	return res;
}

#elif defined(_WIN32)

float strtof_c_locale(const char *nptr, char **endptr)
{
	float res;

	// Store old threadlocale state
	int cfgtlocale_old = _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
	char *orig_locale = NULL;
	if (cfgtlocale_old != -1) {
		// Store current locale
		orig_locale = setlocale(LC_NUMERIC, NULL);
		setlocale(LC_NUMERIC, "C");
	}
	res = strtof(nptr, endptr);
	if (orig_locale != NULL) {
		// Restore the old locale
		setlocale(LC_NUMERIC, orig_locale);
	}
	if (cfgtlocale_old != _ENABLE_PER_THREAD_LOCALE && cfgtlocale_old != -1) {
		// Restore the old threadlocale state
		_configthreadlocale(cfgtlocale_old);
	}

	return res;
}

int snprintf_c_locale(char * restrict str, size_t size, const char * restrict format, ...)
{
	int res;

	// Store old threadlocale state
	int cfgtlocale_old = _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
	char *orig_locale = NULL;
	if (cfgtlocale_old != -1) {
		// Store current locale
		orig_locale = setlocale(LC_NUMERIC, NULL);
		setlocale(LC_NUMERIC, "C");
	}

	va_list args;
    va_start(args, format);
	res = vsnprintf(str, size, format, args);
	va_end(args);

	if (orig_locale != NULL) {
		// Restore the old locale
		setlocale(LC_NUMERIC, orig_locale);
	}
	if (cfgtlocale_old != _ENABLE_PER_THREAD_LOCALE && cfgtlocale_old != -1) {
		// Restore the old threadlocale state
		_configthreadlocale(cfgtlocale_old);
	}

	return res;
}

#elif defined(__ANDROID__) && (__ANDROID_API__ < 21)

float strtof_c_locale(const char *nptr, char **endptr)
{
	// Android API level < 21 has no locales support
	return strtof(nptr, endptr);
}

int snprintf_c_locale(char * restrict str, size_t size, const char * restrict format, ...)
{
	// Android API level < 21 has no locales support
	va_list args;
    va_start(args, format);
	return vsnprintf(str, size, format, args);
	va_end(args);
}

#else // Version for all other OSes

float strtof_c_locale(const char *nptr, char **endptr)
{
	float res;

	locale_t orig_locale = (locale_t)0;
	locale_t locale = newlocale(LC_NUMERIC_MASK, "C", (locale_t)0);
	if (locale != (locale_t)0) {
		// Store current locale
		orig_locale = uselocale(locale);
	}
	res = strtof(nptr, endptr);
	if (locale != (locale_t)0) {
		// Restore old locale
		uselocale(orig_locale);
		freelocale(locale);
	}

	return res;
}

int snprintf_c_locale(char * restrict str, size_t size, const char * restrict format, ...)
{
	int res;

	locale_t orig_locale = (locale_t)0;
	locale_t locale = newlocale(LC_NUMERIC_MASK, "C", (locale_t)0);
	if (locale != (locale_t)0) {
		// Store current locale
		orig_locale = uselocale(locale);
	}

	va_list args;
    va_start(args, format);
	res = vsnprintf(str, size, format, args);
	va_end(args);

	if (locale != (locale_t)0) {
		// Restore old locale
		uselocale(orig_locale);
		freelocale(locale);
	}

	return res;
}

#endif
