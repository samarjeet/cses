#include<iostream>

int main(int argc, char** argv){

	int t;
	long long int x,y, val;
	std::cin >> t;
	
	for (int i=0; i< t;++i){
		std::cin >> y >> x;
		bool rowD = false;
		// y roe x col
		y--;
		x--;

		if (y >= x) rowD = true;
		if (rowD){
			if (y%2==0) val = y*y + x +1;
			else val = (y+1)*(y+1) - x; 
		}
		else {
			if (x%2 == 0) val = (x+1)*(x+1) - y;	
			else val = x*x + y +1;
		}

		std::cout << val << "\n";
	}
	return 0;
}
