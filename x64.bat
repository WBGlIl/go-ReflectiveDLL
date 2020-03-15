del dllmain.a
go build -a -v --ldflags "-s -w" -buildmode=c-archive -o dllmain.a
gcc dllmain.def dllmain.a -shared -lwinmm -lWs2_32 -o dllmain.dll
move dllmain.dll reflective_dll.x64.dll
