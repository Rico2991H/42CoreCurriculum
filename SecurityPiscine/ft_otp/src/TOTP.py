import hmac
import base64
import time
import struct

def hotp(key, counter):
	key = bytes.fromhex(key)
	counter = struct.pack('>Q', counter)
	mac = hmac.new(key ,counter, 'sha1').digest()
	offset = mac[-1] & 0x0f
	binary = struct.unpack('>L', mac[offset:offset+4])[0] & 0x7fffffff 
	return str(binary)[-6:].zfill(6)

def	totp(key):
	time_step = 30
	return hotp(key, int(time.time()) // time_step)