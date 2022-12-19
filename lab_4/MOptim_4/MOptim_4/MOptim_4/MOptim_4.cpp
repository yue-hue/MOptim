/*#include <iostream>
#include <cmath>

double x[5] = {100,100,100,100,100};///{ 1, 1, 1, 1, 1 };
int d[5][5] = { {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1} };
double y[5] = { 1, 1, 1, 1, 1 };
double D = 1;

double eps = 0.01;
double lambda = 0;


void replace_d() {
	int temp[5];

	for (int i = 0; i < 5; i++) {
		temp[i] = d[0][i];
	}

	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			d[i][j] = d[i + 1][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		d[4][i] = temp[i];
	}

	for (int i = 0; i < 5; i++) {
		d[0][i] = x[i] - y[i];
	}
}

void find_xi(int i) {
	double rigth_side = 0;
	int k = 0;

	for (int j = 0; j < 5; j++) {
		if (d[i][j] != 0) {
			k = j;
		}
	}

	switch(k) {
		case 0: {
			rigth_side = ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
			lambda = (-1) * ((rigth_side / 15) + x[0]);
			break;
		}
		case 1: {
			rigth_side = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
			lambda = (-1) * ((rigth_side / 4) + x[1]);
			break;
		}
		case 2: {
			rigth_side = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
			lambda = (-1) * ((rigth_side / 10) + x[2]);
			break;
		}
		case 3: {
			rigth_side = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
			lambda = (-1) * ((rigth_side / 2) + x[3]);
			break;
		}
		case 4: {
			rigth_side = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]);
			lambda = (-1) * ((rigth_side / 20) + x[4]);
			break;
		}
	}

	for (int i = 0; i < 5; i++) {
		x[i] += lambda * d[k][i];
	}
}

int main()
{
	do {
		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				find_xi(4);
				for (int i = 0; i < 5; i++) {
					y[i] = x[i];
				}
			}
			else
				find_xi(i-1);

			double func = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

			std::cout << func << "   " << x[0] << "   " << x[1] << "   " << x[2] << "   " << x[3] << "   " << x[4] << std::endl;
		}

		replace_d();

		D = sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2) + pow(x[2] - y[2], 2) + pow(x[3] - y[3], 2) + pow(x[4] - y[4], 2));

		for (int i = 0; i < 5; i++) {
			if (x[i] != y[i]) {
				for (int j = 0; j < 5; j++) {
					y[j] = x[j];
				}
				break;
			}
		}				
		
	} while (D > eps);

	return 0;
}*/


#include <iostream>
#include <cmath>

double x[5] = { 20,20,20,20,20 };//{ 1, 1, 1, 1, 1 };  
int d[5][5] = { {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1} };
double y[5] = { 1, 1, 1, 1, 1 };
double D = 1;

double eps = 0.01;
double lambda = 0;

double func = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

void replace_d() {
	int temp[5];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			d[i][j] = d[i + 1][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		d[4][i] = round(x[i] - y[i]);
	}
}

double quadratic_interpolation_method(int x_num) {
	double x_min = 0;
	double min_ip_x = 0;
	int min_pos = 0;
	double min_ip_f = 0;
	double min_func = 0;
	double x_fraction = 0;
	double F_fraction = 0;

	int h = 1;
	double eps = 0.1;
	bool is_x_changed = false;

	double it_x[3] = { 0, 0, 0 };
	double it_f[3] = { 0, 0, 0 };	

	switch (x_num) {
		case 1: {

			it_x[0] = x[1];

			do {
				if (is_x_changed) {
					it_f[0] = ((3500 + 7.5 * pow(it_x[0], 2)) / it_x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(it_x[1], 2)) / it_x[1]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
				}
				else {
					it_x[1] = it_x[0] + h;

					it_f[0] = ((3500 + 7.5 * pow(it_x[0], 2)) / it_x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(it_x[1], 2)) / it_x[1]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

					if (it_f[0] > it_f[1]) {
						it_x[2] = it_x[0] + (2 * h);
					}
					else {
						it_x[2] = it_x[0] - h;
					}
				}

				it_f[2] = ((3500 + 7.5 * pow(it_x[2], 2)) / it_x[2]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				min_func = it_f[0];
				for (int i = 0; i < 3; i++) {
					if (it_f[i] < min_func) {
						min_func = it_f[i];
						min_pos = i;
					}

				}

				double numerator = ((pow(it_x[1], 2) - pow(it_x[2], 2)) * it_f[0]) + ((pow(it_x[2], 2) - pow(it_x[0], 2)) * it_f[1]) + ((pow(it_x[0], 2) - pow(it_x[1], 2)) * it_f[2]);;
				double denominator = ((it_x[1] - it_x[2]) * it_f[0]) + ((it_x[2] - it_x[0]) * it_f[1]) + ((it_x[0] - it_x[1]) * it_f[2]);

				min_ip_x = (0.5) * numerator / denominator;

				min_ip_f = ((3500 + 7.5 * pow(min_ip_x, 2)) / min_ip_x) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				F_fraction = ((min_func - min_ip_f) / min_ip_f);
				x_fraction = ((it_x[min_pos] - min_ip_x) / min_ip_x);

				if ((F_fraction > eps) || (x_fraction > eps)) {
					if ((min_ip_x > it_x[0] && min_ip_x < it_x[2]) || (min_ip_x < it_x[0] && min_ip_x > it_x[2])) {
						if (it_x[min_pos] > min_ip_x) {
							it_x[0] = floor(min_ip_x);
							it_x[1] = min_ip_x;
							it_x[2] = ceil(min_ip_x);
							is_x_changed = true;
						}
						else {
							it_x[1] = it_x[min_pos];
							it_x[0] = floor(it_x[min_pos]);
							it_x[2] = ceil(it_x[min_pos]);
							is_x_changed = true;
						}
					}
					else if ((min_ip_x < it_x[0] && min_ip_x < it_x[2]) || (min_ip_x > it_x[0] && min_ip_x > it_x[2])) {
						it_x[0] = min_ip_x;
						is_x_changed = false;
					}
				}

			} while ((F_fraction > eps) || (x_fraction > eps));

			x_min = min_ip_x;
			
			break;
		}
		case 2: {
			it_x[0] = x[1];	

			do {
				if (is_x_changed) {
					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(it_x[0], 2)) / it_x[0]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(it_x[1], 2)) / it_x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
				}
				else {
					it_x[1] = it_x[0] + h;

					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(it_x[0], 2)) / it_x[0]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(it_x[1], 2)) / it_x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

					if (it_f[0] > it_f[1]) {
						it_x[2] = it_x[0] + (2 * h);
					}
					else {
						it_x[2] = it_x[0] - h;
					}
				}

				it_f[2] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(it_x[2], 2)) / it_x[2]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				min_func = it_f[0];
				for (int i = 0; i < 3; i++) {
					if (it_f[i] < min_func) {
						min_func = it_f[i];
						min_pos = i;
					}

				}

				double numerator = ((pow(it_x[1], 2) - pow(it_x[2], 2)) * it_f[0]) + ((pow(it_x[2], 2) - pow(it_x[0], 2)) * it_f[1]) + ((pow(it_x[0], 2) - pow(it_x[1], 2)) * it_f[2]);;
				double denominator = ((it_x[1] - it_x[2]) * it_f[0]) + ((it_x[2] - it_x[0]) * it_f[1]) + ((it_x[0] - it_x[1]) * it_f[2]);

				min_ip_x = (0.5) * numerator / denominator;

				min_ip_f = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(min_ip_x, 2)) / min_ip_x) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				F_fraction = ((min_func - min_ip_f) / min_ip_f);
				x_fraction = ((it_x[min_pos] - min_ip_x) / min_ip_x);

				if ((F_fraction > eps) || (x_fraction > eps)) {
					if ((min_ip_x > it_x[0] && min_ip_x < it_x[2]) || (min_ip_x < it_x[0] && min_ip_x > it_x[2])) {
						if (it_x[min_pos] > min_ip_x) {
							it_x[0] = floor(min_ip_x);
							it_x[1] = min_ip_x;
							it_x[2] = ceil(min_ip_x);
							is_x_changed = true;
						}
						else {
							it_x[1] = it_x[min_pos];
							it_x[0] = floor(it_x[min_pos]);
							it_x[2] = ceil(it_x[min_pos]);
							is_x_changed = true;
						}
					}
					else if ((min_ip_x < it_x[0] && min_ip_x < it_x[2]) || (min_ip_x > it_x[0] && min_ip_x > it_x[2])) {
						it_x[0] = min_ip_x;
						is_x_changed = false;
					}
				}

			} while ((F_fraction > eps) || (x_fraction > eps));

			x_min = min_ip_x;
			
			break;
		}
		case 3: {

			it_x[0] = x[1];

			do {
				if (is_x_changed) {
					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(it_x[0], 2)) / it_x[0]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(it_x[1], 2)) / it_x[1]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
				}
				else {
					it_x[1] = it_x[0] + h;

					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(it_x[0], 2)) / it_x[0]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(it_x[1], 2)) / it_x[1]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

					if (it_f[0] > it_f[1]) {
						it_x[2] = it_x[0] + (2 * h);
					}
					else {
						it_x[2] = it_x[0] - h;
					}
				}

				it_f[2] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(it_x[2], 2)) / it_x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				min_func = it_f[0];
				for (int i = 0; i < 3; i++) {
					if (it_f[i] < min_func) {
						min_func = it_f[i];
						min_pos = i;
					}

				}

				double numerator = ((pow(it_x[1], 2) - pow(it_x[2], 2)) * it_f[0]) + ((pow(it_x[2], 2) - pow(it_x[0], 2)) * it_f[1]) + ((pow(it_x[0], 2) - pow(it_x[1], 2)) * it_f[2]);;
				double denominator = ((it_x[1] - it_x[2]) * it_f[0]) + ((it_x[2] - it_x[0]) * it_f[1]) + ((it_x[0] - it_x[1]) * it_f[2]);

				min_ip_x = (0.5) * numerator / denominator;

				min_ip_f = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(min_ip_x, 2)) / min_ip_x) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				F_fraction = ((min_func - min_ip_f) / min_ip_f);
				x_fraction = ((it_x[min_pos] - min_ip_x) / min_ip_x);

				if ((F_fraction > eps) || (x_fraction > eps)) {
					if ((min_ip_x > it_x[0] && min_ip_x < it_x[2]) || (min_ip_x < it_x[0] && min_ip_x > it_x[2])) {
						if (it_x[min_pos] > min_ip_x) {
							it_x[0] = floor(min_ip_x);
							it_x[1] = min_ip_x;
							it_x[2] = ceil(min_ip_x);
							is_x_changed = true;
						}
						else {
							it_x[1] = it_x[min_pos];
							it_x[0] = floor(it_x[min_pos]);
							it_x[2] = ceil(it_x[min_pos]);
							is_x_changed = true;
						}
					}
					else if ((min_ip_x < it_x[0] && min_ip_x < it_x[2]) || (min_ip_x > it_x[0] && min_ip_x > it_x[2])) {
						it_x[0] = min_ip_x;
						is_x_changed = false;
					}
				}

			} while ((F_fraction > eps) || (x_fraction > eps));

			x_min = min_ip_x;

			break;
		}
		case 4: {

			it_x[0] = x[1];

			do {
				if (is_x_changed) {
					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(it_x[0], 2)) / it_x[0]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(it_x[1], 2)) / it_x[1]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
				}
				else {
					it_x[1] = it_x[0] + h;

					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(it_x[0], 2)) / it_x[0]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(it_x[1], 2)) / it_x[1]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

					if (it_f[0] > it_f[1]) {
						it_x[2] = it_x[0] + (2 * h);
					}
					else {
						it_x[2] = it_x[0] - h;
					}
				}

				it_f[2] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(it_x[2], 2)) / it_x[2]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				min_func = it_f[0];
				for (int i = 0; i < 3; i++) {
					if (it_f[i] < min_func) {
						min_func = it_f[i];
						min_pos = i;
					}

				}

				double numerator = ((pow(it_x[1], 2) - pow(it_x[2], 2)) * it_f[0]) + ((pow(it_x[2], 2) - pow(it_x[0], 2)) * it_f[1]) + ((pow(it_x[0], 2) - pow(it_x[1], 2)) * it_f[2]);;
				double denominator = ((it_x[1] - it_x[2]) * it_f[0]) + ((it_x[2] - it_x[0]) * it_f[1]) + ((it_x[0] - it_x[1]) * it_f[2]);

				min_ip_x = (0.5) * numerator / denominator;

				min_ip_f = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(min_ip_x, 2)) / min_ip_x) + ((3200 + 10 * pow(x[4], 2)) / x[4]);

				F_fraction = ((min_func - min_ip_f) / min_ip_f);
				x_fraction = ((it_x[min_pos] - min_ip_x) / min_ip_x);

				if ((F_fraction > eps) || (x_fraction > eps)) {
					if ((min_ip_x > it_x[0] && min_ip_x < it_x[2]) || (min_ip_x < it_x[0] && min_ip_x > it_x[2])) {
						if (it_x[min_pos] > min_ip_x) {
							it_x[0] = floor(min_ip_x);
							it_x[1] = min_ip_x;
							it_x[2] = ceil(min_ip_x);
							is_x_changed = true;
						}
						else {
							it_x[1] = it_x[min_pos];
							it_x[0] = floor(it_x[min_pos]);
							it_x[2] = ceil(it_x[min_pos]);
							is_x_changed = true;
						}
					}
					else if ((min_ip_x < it_x[0] && min_ip_x < it_x[2]) || (min_ip_x > it_x[0] && min_ip_x > it_x[2])) {
						it_x[0] = min_ip_x;
						is_x_changed = false;
					}
				}

			} while ((F_fraction > eps) || (x_fraction > eps));

			x_min = min_ip_x;

			break;
		}
		case 5: {

			it_x[0] = x[1];

			do {
				if (is_x_changed) {
					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(it_x[0], 2)) / it_x[0]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(it_x[1], 2)) / it_x[1]);
				}
				else {
					it_x[1] = it_x[0] + h;

					it_f[0] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(it_x[0], 2)) / it_x[0]);
					it_f[1] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(it_x[1], 2)) / it_x[1]);

					if (it_f[0] > it_f[1]) {
						it_x[2] = it_x[0] + (2 * h);
					}
					else {
						it_x[2] = it_x[0] - h;
					}
				}

				it_f[2] = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(it_x[2], 2)) / it_x[2]);

				min_func = it_f[0];
				for (int i = 0; i < 3; i++) {
					if (it_f[i] < min_func) {
						min_func = it_f[i];
						min_pos = i;
					}
				}

				double numerator = ((pow(it_x[1], 2) - pow(it_x[2], 2)) * it_f[0]) + ((pow(it_x[2], 2) - pow(it_x[0], 2)) * it_f[1]) + ((pow(it_x[0], 2) - pow(it_x[1], 2)) * it_f[2]);;
				double denominator = ((it_x[1] - it_x[2]) * it_f[0]) + ((it_x[2] - it_x[0]) * it_f[1]) + ((it_x[0] - it_x[1]) * it_f[2]);

				min_ip_x = (0.5) * numerator / denominator;

				min_ip_f = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(min_ip_x, 2)) / min_ip_x);

				F_fraction = ((min_func - min_ip_f) / min_ip_f);
				x_fraction = ((it_x[min_pos] - min_ip_x) / min_ip_x);

				if ((F_fraction > eps) || (x_fraction > eps)) {
					if ((min_ip_x > it_x[0] && min_ip_x < it_x[2]) || (min_ip_x < it_x[0] && min_ip_x > it_x[2])) {
						if (it_x[min_pos] > min_ip_x) {
							it_x[0] = floor(min_ip_x);
							it_x[1] = min_ip_x;
							it_x[2] = ceil(min_ip_x);
							is_x_changed = true;
						}
						else {
							it_x[1] = it_x[min_pos];
							it_x[0] = floor(it_x[min_pos]);
							it_x[2] = ceil(it_x[min_pos]);
							is_x_changed = true;
						}
					}
					else if ((min_ip_x < it_x[0] && min_ip_x < it_x[2]) || (min_ip_x > it_x[0] && min_ip_x > it_x[2])) {
						it_x[0] = min_ip_x;
						is_x_changed = false;
					}
				}

			} while ((F_fraction > eps) || (x_fraction > eps));

			x_min = min_ip_x;

			break;
		}
	}

	return x_min;
}

void find_xi(int i) {
	int k = 0;
	int it = 0;
	double result_x = 0;

	for (int j = 0; j < 5; j++) {

		if (d[i][j] != 0) {
			k = j;

			switch (k) {
				case 0: {
					result_x = quadratic_interpolation_method(1);
					
					break;
				}
				case 1: {
					result_x = quadratic_interpolation_method(2);
					
					break;
				}
				case 2: {
					result_x = quadratic_interpolation_method(3);
					
					break;
				}
				case 3: {
					result_x = quadratic_interpolation_method(4);
					
					break;
				}
				case 4: {
					result_x = quadratic_interpolation_method(5);
					
					break;
				}
			}

			lambda = (result_x - x[k]) / d[i][j];
			x[k] += lambda;
		}
	}
}

int main()
{
	func = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
	std::cout << func << "   " << x[0] << "   " << x[1] << "   " << x[2] << "   " << x[3] << "   " << x[4] << std::endl;

	for (int j = 0; j < 5; j++) {
		y[j] = x[j];
	}

	do {
		for (int i = 0; i < 5; i++) {
			find_xi(i);

			func = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
			std::cout << func << "   " << x[0] << "   " << x[1] << "   " << x[2] << "   " << x[3] << "   " << x[4] << std::endl;
		}

		replace_d();

		D = sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2) + pow(x[2] - y[2], 2) + pow(x[3] - y[3], 2) + pow(x[4] - y[4], 2));

		for (int i = 0; i < 5; i++) {
			if (x[i] != y[i]) {
				for (int j = 0; j < 5; j++) {
					y[j] = x[j];
				}
				break;
			}
		}
	} while (D > eps);

	func = ((3500 + 7.5 * pow(x[0], 2)) / x[0]) + ((1000 + 2 * pow(x[1], 2)) / x[1]) + ((10000 + 5 * pow(x[2], 2)) / x[2]) + ((450 + pow(x[3], 2)) / x[3]) + ((3200 + 10 * pow(x[4], 2)) / x[4]);
	std::cout << "\nResult:\n" << func << "   " << x[0] << "   " << x[1] << "   " << x[2] << "   " << x[3] << "   " << x[4] << std::endl;
	return 0;
}