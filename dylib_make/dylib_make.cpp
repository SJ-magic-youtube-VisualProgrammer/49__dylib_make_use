#include <iostream>
#include "dylib_make.h"

dylib_make::dylib_make(){
    std::cout << "dylib_make::dylib_make was called" << std::endl;
}

dylib_make::~dylib_make(){
    std::cout << "dylib_make::~dylib_make was called" << std::endl;
}

void dylib_make::sj_execute(){
    std::cout << "dylib_make::sj_execute was called" << std::endl;
}

// extern "C"{
	dylib_make* GetInterface(void){
		return new dylib_make();
	}
	
	void DestroyInterface(dylib_make* instance){
		delete instance;
		instance = NULL;
	}
// }


/********************
// How to use

#include <iostream>
#include <dlfcn.h>
#include "dylib_make.h"

int main (int argc, const char * argv[]) {
    void* dylib_handle = dlopen("./libdylib_make.dylib", RTLD_LAZY);
	
    IFCreator GetInterface = (IFCreator)dlsym(dylib_handle, "GetInterface");
    IFDestructor DestroyInterface = (IFDestructor)dlsym(dylib_handle, "DestroyInterface");
	
	dylib_make* dylibIF = GetInterface();
	dylibIF->sj_execute();
    DestroyInterface(dylibIF);

	dlclose(dylib_handle);
}
********************/

