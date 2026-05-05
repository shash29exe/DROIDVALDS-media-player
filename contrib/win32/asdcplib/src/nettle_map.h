#include <nettle/aes.h>
#include <nettle/sha1.h>
#include <nettle/bignum.h>

typedef aes128_ctx AES_KEY;
#define SHA_DIGEST_LENGTH SHA1_DIGEST_SIZE
typedef sha1_ctx SHA_CTX;
#define SHA1_Init(x) sha1_init(x)
#define SHA1_Update(a,b,c)  sha1_update(a,c,b)
#define SHA1_Final(a,b) sha1_digest(b, sizeof(a), a)
#define AES_encrypt(a,b,c)  aes128_encrypt(c, sizeof(a), b, a)
#define AES_decrypt(a, b, c) aes128_decrypt(c, sizeof(a), b, a)
#define AES_decrypt(a, b, c) aes128_decrypt(c, sizeof(a), b, a)
#define AES_set_encrypt_key(a, b, c)  aes128_set_encrypt_key(c, a)
