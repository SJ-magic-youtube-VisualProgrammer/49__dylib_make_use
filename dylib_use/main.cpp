#include <iostream>
#include <dlfcn.h>
#include "dylib_make.h"

int main (int argc, const char * argv[]) {
	/********************
	********************/
    void* dylib_handle = dlopen("./libdylib_make.dylib", RTLD_LAZY);
	if(dylib_handle == NULL){
		printf("dylib open Error(NULL).\n");
		fflush(stdout);
		return 1;
	}else{
		printf("dylib handle = %p\n", dylib_handle);
		fflush(stdout);
	}
	
	/********************
	dlsym:シンボルをvoid*型として取り出す→ここでは関数ポインタを取り出している
	********************/
    IFCreator GetInterface = (IFCreator)dlsym(dylib_handle, "GetInterface");
	if(GetInterface == NULL){
		printf("dlsym GetInterface Error: %s\n", dlerror());
		return 1;
	}
	
    IFDestructor DestroyInterface = (IFDestructor)dlsym(dylib_handle, "DestroyInterface");
	if(DestroyInterface == NULL){
		printf("dlsym DestroyInterface Error: %s\n", dlerror());
		return 1;
	}
	
	/********************
	********************/
	dylib_make* dylibIF = GetInterface();
	dylibIF->sj_execute();
    DestroyInterface(dylibIF);

	if(!dlclose(dylib_handle)){
		printf("dlclose OK\n");
		fflush(stdout);
	}

    return 0;
}

