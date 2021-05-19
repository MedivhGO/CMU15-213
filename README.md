# CSAPPLab

- [x] boom

- [ ] cachelab

- [ ] archlab

- [ ] malloclab

- [ ] datalab

- [ ] perflab

- [ ] proxylab

- [ ] shlab

- [ ] target1


# Note


```shell
apt-get install gcc-multilib
```

执行上述命令，在64位平台上产生32位的程序或文件。

如果在wsl中运行程序提示 exec format error

执行如下命令

```
sudo apt install qemu-user-static
sudo update-binfmts --install i386 /usr/bin/qemu-i386-static --magic '\x7fELF\x01\x01\x01\x03\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x03\x00\x01\x00\x00\x00' --mask '\xff\xff\xff\xff\xff\xff\xff\xfc\xff\xff\xff\xff\xff\xff\xff\xff\xf8\xff\xff\xff\xff\xff\xff\xff'

sudo service binfmt-support start

sudo dpkg --add-architecture i386
sudo apt update
sudo apt install gcc:i386
```
