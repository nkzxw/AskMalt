#pragma once

#include <variant>
#include <memory>
#include "Predefined.h"
#include "Mark.h"
//#include "Objects.h"
//#include "Function.h"

namespace amalt {
	///*
	class Value;

	using String = std::wstring;
	using Tuple = std::vector<Value>;
	using Dict = std::unordered_map<String, Value>;
	//class String;
	//class Tuple;
	//class Dict;
	class List;
	class Function;
	class RTFunction;
	class NativeFunction;
	class UserDatas;
	//*/
	typedef std::shared_ptr<String> RString;
	typedef std::shared_ptr<Tuple> RTuple;
	typedef std::shared_ptr<List> RList;
	typedef std::shared_ptr<Dict> RDict;
	typedef std::shared_ptr<UserDatas> RUserDatas;
	using RRTFunction = std::shared_ptr<RTFunction>;
	using RNativeFunction = std::shared_ptr<NativeFunction>;

	using RValue = std::variant<
		// atom
		bool,
		ui64, i64, f64,
		// ref object
		RString,
		RTuple,
		RList,
		RDict,
		RRTFunction,
		RNativeFunction,
		// userdata
		RUserDatas
	>;

	enum Type {
		NIL,

		BOOLT,
		CHART,
		INTT,
		UINTT,
		FLOATT,

		STRINGT,
		TUPLET,
		LISTT,
		DICTT,
		OBJECTT,

		USERDATA,

		FUNCTIONT,
		NATIVE,
	};

	class Value {
	public:
		Type tp;
		RValue val;

		Value(Type t, RValue v) : tp(t), val(std::move(v)) {}
		Value(Value &) = default;
	};
}