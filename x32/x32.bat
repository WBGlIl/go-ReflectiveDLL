set GOARCH=386
set CGO_ENABLED=1
go build --ldflags "-s -w" -buildmode=c-archive -o dllmain.a
set path=D:\mingw32\bin\;%path%
gcc dllmain.def dllmain.a -shared -lwinmm -lWs2_32 -o dllmain.dll
move dllmain.dll reflective_dll.dll 