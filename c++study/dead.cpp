// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;
//
// int main() {
//     srand(time(0));
//     string a[4] = {"1","2","3","4"};
//     int result = rand() % 4;
//     for (int i = 0; i < 4; i++) {
//         cout << a[i] << endl;
//     }
//     return 0;
// }

// 순서대로 출력됨 -> random_shuffle 사용

// #include <iostream>
// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// using namespace std;
//
// int main() {
//     srand(time(0));
//     string a[4] = {"1", "2", "3", "4"};
//     random_shuffle(a, a + 4);  // C++11 이하
//     // 또는 C++17 이상에서는:
//     // shuffle(a, a + 4, default_random_engine(time(0)));
//
//     for (int i = 0; i < 4; i++) {
//         cout << a[i] << endl;
//     }
//     return 0;
// }


// 항상 같은 값이 나옴
// random_shuffle이
//for (int i = n-1; i > 0; --i)
//swap(a[i], a[rand() % (i+1)]); 이렇게 작동하기 때문
//랜덤 시드 사용을 위해
//    random_device rd;
//    mt19937 gen(rd());  추가

// #include <iostream>
// #include <algorithm>
// #include <random>
// #include <string>
// using namespace std;
//
// int main() {
//     random_device rd;              // 하드웨어 기반 시드
//     mt19937 gen(rd());             // Mersenne Twister 엔진
//     int a[4] = {1, 2, 3};
//     shuffle(a, a + 2, gen);        // 현대적 랜덤 셔플
//     for (int i = 0; i < 4; i++) cout << a[i] << endl;
// }


#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    int a[3] = {1, 2, 3};

    for (int j = 0; j < 3; j++) {
        shuffle(a, a + 3, gen); // 배열 전체 셔플
        for (int i = 0; i < 2; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}