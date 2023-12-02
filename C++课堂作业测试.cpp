
//#include<iostream>
//using namespace std;
//
//struct A { A() { cout << 'A'; } };
//struct B { B() { cout << 'B'; } };
//struct C : A { C() { cout << 'C'; } };
//struct D : A, virtual B { D() { cout << 'D'; } };
//struct E : A, virtual B, virtual C {
//	D d;
//	E() { cout << 'E'; }
//};
//struct F : A, virtual B, virtual C, D, E {
//	C  c;
//	E  e;
//	F() { cout << 'F'; }
//};
//void main(void)
//{
//	A  a;
//	B  b;
//	C  c;
//	D  d;
//	E  e;
//	F  f;
//}
//class A {
//	int x;
//	virtual int f() { return 0; }
//	virtual int g() = 0;
//protected:
//	int  y;
//public:
//	 A() { }
//} ;
//struct B : A {
//	//A::x;
//	using A::y;
//	int f() { return 1L; };
//	int g(int) { return 1; }
//} ;
////A* p = new A;
////B* q = new B;
//int f(A, B);
//A g(B&);
//int h(B*);
//struct A {
//	int a = 0;
//	int x = 1;
//	void f() { cout << "A::f()"; }
//	virtual void g() { cout << "A::g()"; }
//	A(int x) { }
//};
//struct B : A {
//	int x = 11;
//	int y = 12;
//	virtual void f() { cout << "B::f()"; }//只有这个是虚函数
//	void g() { cout << "B::g()"; }//是虚函数
//	void h() { cout << "B::h()"; }
//	B(int x) : A(x) { }
//}b(0);
//struct C : B {
//	int x = 21;
//	int y = 22;
//	int z = 23;
//	void f() { cout << "C::f()"; }//不是虚函数
//	void g() { cout << "C::g()"; }//是虚函数
//	virtual void h() { cout << "C::h()"; }
//	C(int x) : B(x) { }
//} c(1);
//int main() {
//	A* p = & c;
//	p->f();
//	p->g();
//	//p->h();
//	cout << p->a;
//	cout << p->x;
//	//cout << p->y;
//	//cout << p->z;
//	/**/
//	B* q = &c;
//	q->f();
//	q->g();
//	q->h();
//	cout << p->a;
//	cout << q->x;
//	cout << q->y;
//	//cout << q->z;
//}




//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream> 
//#include <string> 
//class DICT {
//	char** const words;		//存放单词
//	const int max;				//字典可以存放单词的个数
//	int pos;					//当前可以存放单词的空闲位置
//public:
//	DICT(int max);			//max为最大单词个数
//	DICT(const DICT& d);		//深拷贝构造
//	DICT(DICT&& d) noexcept;	//移动构造
//	virtual ~DICT() noexcept;  //析构
//	virtual DICT& operator=(const DICT& d);			  //深拷贝赋值
//	virtual DICT& operator=(const DICT&& d) noexcept;  //移动赋值
//	virtual int operator( )(const char* word) const;  		  //查找单词位置,-1表示没找到
//	virtual DICT& operator<<(const char* word);		  //若字典中没有该单词则加入
//	virtual DICT& operator>>(const char* word);		  //删除字典中的这个单词,后面的单词往前移动
////字典中的单词保持连续存放
//	virtual const char* operator[](int n) const;	  		  //取出第n(n>=0)个单词
//};
//
//DICT::DICT(int max):max(max),words(new char*[max])
//{
//	pos = 0;
//	//(* (char***)(&words)) = NULL;
//	///**((int*)(& this->max)) = max;*/
//	//pos = 0;
//}
//DICT::DICT(const DICT& d):max(d.max), words(new char* [d.max])
//{
//	pos = d.pos;
//	for (int i = 0; i < d.pos; i++)
//	{
//		words[i] = new char[strlen(d.words[i])];
//		strcpy(words[i], d.words[i]);
//	}
//}
//DICT:: DICT(DICT&& d) noexcept :max(d.max), words(d.words),pos(d.pos)
//{
//
//	/*pos = d.pos;
//	for (int i = 0; i < d.pos; i++)
//	{
//		words[i] = new char[strlen(*d.words)];
//		strcpy(words[i], d.words[i]);
//	}*/
//}
//DICT& DICT::operator=(const DICT& d)
//{
//	DICT x(d);
//	DICT& B = x;
//	return B;
//}
//DICT& DICT::operator=(const DICT&& d)noexcept
//{
//	DICT A(d);
//	DICT& B = A;
//	return B;
//
//}
//DICT::~DICT()
//{
//	if (words) {
//		for (int i = 0; i < pos; i++)
//			delete[]words[i];
//		delete []words;
//	}
//}
//int DICT::operator()(const char* word)const
//{
//	for (int i = 0; i < pos; i++)
//		if (!strcmp(words[i], word))
//			return i;
//	return -1;
//}
// DICT& DICT::operator<<(const char* word)
//{
//	 if ((*this)(word) || pos >= max || !(words[pos] = new char[strlen(word) + 1]))
//		 return *this;
//	 strcpy(words[pos++], word);
//	 return *this;
//}
// DICT& DICT::operator>>(const char* word)
// {
//	 int x;
//	 x = (*this)(word);
//	 if (!pos || x==-1)
//		 return *this;
//	 else
//	 {
//		 for (int i = x; i < pos-1; i++)
//		 {
//			 words[i] = new char[strlen(words[i+1])];
//			 strcpy(words[i], words[i+1]);
//		 }
//		 pos--;
//	 }
//	 DICT A(*this);
//	 DICT& B = A;
//	 return B;
//		 
// }
// const char* DICT::operator[](int n)const
// {
//	 return n < pos ? words[n] : 0;
// }
//#include <iostream> 
//#include <string> 
//class STRING {
//	char* str;
//public:
//	int strlen() const; 						//返回字符串的长度
//	int strcmp(const STRING& s) const; 		//字符串比较
//	STRING& strcpy(const STRING& s); 		//深拷贝赋值
//	STRING& strcat(const STRING& s); 		//将字符串s尾加到当前字符串
//	STRING& operator+=(const STRING& s);	//实现strcat()的功能
//	STRING(const char* s);
//	~STRING();
//};
//int x(char* const* str)
//{
//	return strlen(*str);
//}
//int STRING::strlen()const
//{	
//	return x(&str);
//}
//int y(char* const* s1, char* const* s2)
//{
//	return(strcmp(*s1, *s2));
//}
//int STRING::strcmp(const STRING& s)const
//{
//	return y(&str, &(s.str));
//}
//
//STRING& STRING::strcpy(const STRING& s)
//{
//	 STRING x(s);
//	 STRING& Y = x;
//	 return Y;
//}
//char* z(char* const* s1, char* const* s2)
//{
//	return strcat(*s1, *s2);
//}
//STRING& STRING::strcat(const STRING& s)
//{
//	
//	STRING A(z(&str, &(s.str)));
//	STRING& B = A;
//	return B;
//}
//STRING& STRING::operator+=(const STRING& s)
//{
//	return strcat(s);
//}
//STRING::STRING(const char *s)
//{
//	int x = 0;
//	for (int x = 0; s[x] != 0; x++)
//	{
//	};
//	str = new char[x+1];
//	for (int i = 0; i <= x; i++)
//	{
//		str[i] = s[i];
//	}
//}
//STRING::~STRING()
//{
//	delete[]str;
//}
//void main(void)
//{
//	STRING s1("I like apple");
//	STRING s2(" and pear");
//	STRING s3(" and orange");
//	std::cout << "Length of s1=" << s1.strlen() << "\n";
//	s1.strcat(s2) += s3;
//	std::cout << "Length of s1=" << s1.strlen() << "\n";
//	s3.strcpy(s2).strcpy(s1);
//	std::cout << "Length of s3=" << s3.strlen() << "\n";
//}
//#include<iostream>
//
//using namespace std;
//struct A {
//    int  i;
//    A(int v) { i = v; printf("A(%d) ", i); }
//    A(const A& a) { i = a.i; printf("A(A&) "); }
//    ~A() { printf("~A(%d) ", i); }
//    operator int() const { printf("int() "); return i; }
//    A& operator=(const A& a) {
//        printf("=() ");
//        i = a.i;
//        return *this;
//    }
//};
//int main(void)
//{
//    A x = 1;
//    x = 1;
//    A y = x;
//    y = x;
//    x = 1 + x;
//    A z(x + y);
//    printf("%d %d", y, (int)y);
//}
//

//#include <iostream>
//
//using namespace std;
//
//class INTLIST {
//	int* list; 			//动态申请的内存的指针 
//	int  size; 			//线性表能够存放的元素个数 
//	int  used; 			//线性表已经存放的元素个数
//public:
//	INTLIST(int s); 		//s为线性表能够存放的元素个数 
//	int insert(int v); 		//插入元素v成功时返回1，否则返回0 
//	int remove(int v); 	//删除元素v成功时返回1，否则返回0 
//	int find(int v); 		//查找元素v成功时返回1，否则返回0 
//	int get(int k); 		//取表的第k个元素的值作为返回值
//	~INTLIST();
//};
//INTLIST::INTLIST(int s)
//{
//	size = s;
//	list = new int[s];
//	used = 0;
//}
//int INTLIST::insert(int v)
//{
//	if (used >= size)
//		return 0;
//	list[used++] = v;
//	return 1;
//}
//int INTLIST::remove(int v)
//{
//	if (used <= 0)
//		return 0;
//	used--;
//	return 1;
//}
//int INTLIST::find(int v)
//{
//	for (int i = 0; i < used; i++)
//	{
//		if (list[i] == v)
//			return 1;
//	}
//	return 0;
//}
//int INTLIST::get(int k)
//{
//	if (k<0 || k>used)
//		return 0;
//	return list[k - 1];
//}
//INTLIST::~INTLIST()
//{
//	delete[] list;
//}
//
//
//
//
//
//
//
//
//
//
//
////
////class NODE {
////	char* data;
////	NODE* left, * right;
////public:
////	NODE(char* data);
////	NODE(char* data, NODE* left, NODE* right);
////	~NODE();
////};
////NODE::NODE(char* dat) 
////{
////	data = dat;
////}
////NODE::NODE(char* dat, NODE* le, NODE* rig)
////{
////	data = dat;
////	left = le;
////	right = rig;
////}
////NODE::~NODE()
////{
////	delete[]data;
////	if(left!=NULL)
////		left->~NODE();
////	if (right != NULL)
////		right->~NODE();
////		
////}
//
//
//
//
//
//
//
//
//
////
////class SET {
////	int* set; 			//set用于存放集合元素 
////	int card; 			//card为能够存放的元素个数 
////	int used; 			//used为已经存放的元素个数
////public:
////	SET(int card); 		//card为能够存放的元素个数 
////	~SET();
////	int size(); 			//返回集合已经存放的元素个数 
////	int insert(int v); 		//插入v成功时返回1，否则返回0 
////	int remove(int v); 	//删除v成功时返回1，否则返回0 
////	int has(int v);	//元素v存在时返回1，否则返回0 
////	void print()
////	{
////		cout << card;
////	}
////};
//
//
//
////
////SET::SET(int card0)
////{
////	card = card0;
////	set = new int[card];
////	used = 0;
////}
////SET::~SET()
////{
////	delete[] set;
////}
////int SET::size()
////{
////	return used;
////}
////int SET::insert(int v)
////{
////	if (card == used)
////		return 0;
////	else
////	{
////		set[++used] = v;
////		return 1;
////	}
////}
////int SET::remove(int v)
////{
////	if (used <= 0)
////		return 0;
////	else
////	{
////		used--;
////		return 1;
////	}
////}
////int SET::has(int v)
////{
////	for (int i = 0; i < used; i++)
////	{
////		if (set[i] == v)
////			return 1;
////	}
////	return 0;
//////}
////int main()
////{
////	SET a(66);
////	a.print();
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////class SEQUENCE;
////class TREE {
////	int  item;  //节点的值
////	TREE* left, * right;
////	friend SEQUENCE;
////public:
////	int getNodeNum();		 //返回节点总数
////	int getNodes(int items[]);  //将所有的节点保存到items[ ]中
////};
////class SEQUENCE {
////	int* items; 	//用于保存1个TREE中的所有节点
////	int  size; 		//items中元素的个数
////public:
////	SEQUENCE(TREE& t);  //将t中的所有节点保存到items所指的缓冲区
////};
////int TREE::getNodeNum() {
////	return left->getNodeNum() + right->getNodeNum();
////}
////int TREE::getNodes(int items[])
////{
////	if (left != NULL)
////	{
////		int i = 0;
////		while (items[i] > -9999 && items[i] < 9999)
////		{
////			i++;
////		}
////		items[i - 1] = item;
////		return left->getNodes(items);
////	}
////	if (right!= NULL)
////	{
////		int i = 0;
////		while (items[i] > -9999 && items[i] < 9999)
////		{
////			i++;
////		}
////		items[i - 1] = item;
////		return right->getNodes(items);
////	}
////	return 0;
////}
////SEQUENCE::SEQUENCE(TREE& t)
////{
////	t.getNodes(items);
////}
//
//
//
//
//
////int main() 
////{
////	
////}
////NumToString::NumToString(int num, int srcBase = 10, int desBase = 2)
////{
////}