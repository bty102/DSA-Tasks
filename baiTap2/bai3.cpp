#include <iostream>

// Ham f1
int f1(int x, int y)
{
	if (x == 0)
    	return y;
	else
		return f1(x - 1,  x + y);
}

// Ham f2
int f2(int x, int y)
{
	if (y == 0)
		return 0;
	else if (y > 0 )
		return (x + f2(x, y-1));
	else
		return -f2(x, -y);
}

int main() {
    /*
    f1(4, 2) = f1(3, 6)
    f1(3, 6) = f1(2, 9)
    f1(2, 9) = f1(1, 11)
    f1(1, 11) = f1(0, 12)
    f1(0, 12) = 12
    => f1(4, 2) = 12
    */
    // std::cout << f1(4, 2);

    /*
    f2(3, 2) = (3 + f2(3, 1)) = 6
    f2(3, 1) = (3 + f2(3, 0)) = 3
    f2(3, 0) = 0
    */
    std::cout << f2(3, 2);//6
    return 0;
}
