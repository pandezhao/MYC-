class MyString:public string
{

	public:
		MyString(const char* s):string(s){}
		MyString(const string& str):string(str){}
		MyString():string(){}

	string operator()(int a,int b){
		string result = string::substr(a,b);
		return result;
	}

};

