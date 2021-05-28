/************************************************************
■Xcode(c++)で静的ライブラリ(.a)を作る方法
	https://xxxxxfo.hateblo.jp/entry/2019/03/09/051213

■Xcode4の使い方メモ 〜 ライブラリを作る
	https://white-wheels.hatenadiary.org/entry/20110811/p3

■How to print a list of symbols exported from a dynamic library
	https://stackoverflow.com/questions/4506121/how-to-print-a-list-of-symbols-exported-from-a-dynamic-library

■nm - オブジェクトファイルのシンボル情報を表示する
	https://linuxcommand.net/nm/
	
■[iOS] Static Library (2) ライブラリとヘッダファイルの位置決め
	http://cocoadays.blogspot.com/2010/11/ios-static-library-2.html
************************************************************/
#pragma once

class dylib_make{
public:
    dylib_make();
    ~dylib_make();
	
	virtual void sj_execute();
	// void sj_execute();
};

extern "C" dylib_make* GetInterface(void);
// dylib_make* GetInterface(void);
typedef dylib_make*(*IFCreator)(void);

extern "C" void DestroyInterface(dylib_make*);
// void DestroyInterface(dylib_make*);
typedef void (*IFDestructor)(dylib_make*);
