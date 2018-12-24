#pragma once

#ifndef _DATASTRUCTURE_EXPORT
    #ifdef _DATASTRUCTURE_EXPORTS
        #define _DATASTRUCTURE_EXPORT __declspec(dllexport)
    #else
        #define _DATASTRUCTURE_EXPORT __declspec(dllimport)
    #endif // _DATASTRUCTURE_EXPORTS
#endif // _DATASTRUCTURE_EXPORT
