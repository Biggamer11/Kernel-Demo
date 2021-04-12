# Dev Enviroment
docker run --rm -it -v %cd%:/root/env os-build

## Build x86_64
make build-x86_64

## Powershell
$env:Path += ";C:\Program Files\qemu"
qemu-system-x86_64.exe -cdrom .\dist\x86_64\kernel.iso -L "C:\Program Files\qemu"