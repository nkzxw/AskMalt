# AskMalt
The Ask Malt Programming Language

### Compiled：
Please use MSVC to compile core and extension on Windows.

//玩你🐎的Linux编译，标准库里边的东西报functions that differ only in their return type cannot be overloaded你敢信？

经过大锤确认，目前Linux下C++17标准的实现确实问题，所以只有等问题修复才能在linux下使用了，在此之前这个实现就作为Windows下的独有版本罢

### Warnings:
- 一切不被认定为float/int/uint类型的atom字面量都会被认定为symbol
- 所有有副作用的函数或关键字都会在后边加上!，函数的定义是手动标记的，不排除以后加入强制检查，请谨记
- 还没有实现loop相关的谓词和函数（因为现在只需要一个最小的，能跑的东西）以后会加上
- 目前只支持ANSI编码，Unicode/UTF8就别想了，C++并没有支持这玩意，我也不懂这东西（真让人头大）

### FA&Q:
- When building with VisualStudio, Project Can only be an English Path (Because nijia only supports ASCII)
- Beta Version use std::shared_ptr<T> as memory manager （所以可能有循环引用的问题，在使用Mark<T>替换之前请务必不要造成大量循环引用）
