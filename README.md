# arm on QEMU on Ubuntu16.04

[QEMU でARM エミュレータ環境を作成する \- Qiita]( https://qiita.com/zonomasa/items/b33fba457503e166967a )

## setup
```
sudo apt-get install qemu
sudo apt-get install qemu-user-static
# 32bit
sudo apt-get install gcc-arm-linux-gnueabi
sudo apt-get install g++-arm-linux-gnueabi
sudo apt-get install g++-arm-linux-gnueabihf
# 64bit
sudo apt install g++-aarch64-linux-gnu
```

## how to compile
```
# 32bit
arm-linux-gnueabihf-g++ main.cpp
# 64bit
aarch64-linux-gnu-g++ main.cpp
```

## how to run
[export QEMU\_LD\_PREFIX=/usr/aarch64\-linux\-gnu/]( http://d.hatena.ne.jp/embedded/20140422/p1 )
> qemu-user-staticをインストールしたときにbinfmtの設定も行われているので、aarch64のELFオブジェクトを実行しようとすると自動的にqemu-aarch64-user-staticを経由して実行されるようになっています。

```
# 32bit
qemu-arm -L /usr/arm-linux-gnueabihf/ a.out
## or
export QEMU_LD_PREFIX=/usr/arm-linux-gnueabihf
./a.out

# 64bit
qemu-aarch64 -L /usr/aarch64-linux-gnu/ a.out
## or
export QEMU_LD_PREFIX=/usr/aarch64-linux-gnu/
./a.out
```

### neon
```
arm-linux-gnueabihf-g++ -mfpu=neon -std=c++11 neon_main.cpp -o neon_main
export QEMU_LD_PREFIX=/usr/arm-linux-gnueabihf
./neon_main
```





