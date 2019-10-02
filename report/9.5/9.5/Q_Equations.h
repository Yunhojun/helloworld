#include <string>

class Q_Equations {
public:
	Q_Equations(double a = 1, double b = 0, double c = 0);//생성자
	void add(Q_Equations);//더하기
	void subtract(Q_Equations);//빼기
	std::string toString();//문자열로 표현
	void solve();//x값 계산
	double geta();
	void seta(double a);
	double getb();
	void setb(double b);
	double getc();
	void setc(double c);

private:
	double a_value;
	double b_value;
	double c_value;
	double x_value;
};