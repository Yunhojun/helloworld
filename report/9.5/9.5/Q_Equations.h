#include <string>

class Q_Equations {
public:
	Q_Equations(double a = 1, double b = 0, double c = 0);//������
	void add(Q_Equations);//���ϱ�
	void subtract(Q_Equations);//����
	std::string toString();//���ڿ��� ǥ��
	void solve();//x�� ���
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