# HOTP (HMAC-based One-Time Password)
	HOTP is an algorithm for generating one-time passwords based on HMAC and counter. It is defined in the official specification RFC 4226 and is the basis for the later TOTP (temporary OTP)

## HMAC
   HMAC is a mechanism that uses a secret to create a signature based on a message.

Input data: 
1. Secret key
2. Counter 8-byte value incremented at each generation


1. Convert counter to bytes:
   COUNTER_BYTES = [00 00 00 00 00 00 00 05]

3. Calculate HMAC-SHA1:
   HMAC_RESULT = HMAC_SHA1(SECRET, COUNTER_BYTES) 
   -> [1a f9 15 68 c8 7c 7a 61 37 99 7f 25 b0 dc 76 b3 c0 80 ee d2]

4. Take the last byte of HMAC:
   LAST_BYTE = 0xD2

5. Calculate offset:
   OFFSET = 0xD2 & 0x0F = 0x03 (3 in decimal)

6. Extract 4 bytes starting with offset (3):
   HMAC_SLICE = [15 68 c8 7c]

7. Convert to 31-bit number:
   BINARY = 0x1568c87c & 0x7FFFFFFFFF = 0x1568C87C (359,186,844 in decimal)

8. Take the last 6 digits:
   TOTP = 186844

# background information
	The algorithm MUST use a strong shared secret.  The length of
   the shared secret MUST be at least 128 bits.  This document
   RECOMMENDs a shared secret length of 160 bits.