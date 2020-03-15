package main

import "C"

import (
	"syscall"
	"unsafe"
)


func IntPtr(n int) uintptr {
	return uintptr(n)
}
func StrPtr(s string) uintptr {
	return uintptr(unsafe.Pointer(syscall.StringToUTF16Ptr(s)))
}
func MessageBox(title, text string) {
	user32 := syscall.NewLazyDLL("user32.dll")
	MessageBoxW := user32.NewProc("MessageBoxW")
	MessageBoxW.Call(IntPtr(0), StrPtr(text), StrPtr(title), IntPtr(0))
}

//export OnProcessAttach
func OnProcessAttach() {
	MessageBox("OnProcessAttach","OnProcessAttach")
}
//export test
func test() {
	MessageBox("test","test")
}

func main()  {

}
