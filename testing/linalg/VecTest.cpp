#include <iostream>
#include "../../linalg/vec3.hpp"
#include "../../linalg/vec2.hpp"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    app::vec3<float> v_1(1.0f, 2.0f, 3.0f);
    app::vec3<float> v_2(2.0f, 2.0f, 2.0f);

    app::vec3<float> v_3 = v_1 + v_2;

    v_3.print();
    app::vec3<float> v_unit = v_1.unit();
    v_unit.print();

    app::vec2<float> v2_1(1.0f, 2.0f);
    app::vec2<float> v2_2(3.0f, 4.0f);

    (v2_2 + v2_1).print();

    return 0;
}