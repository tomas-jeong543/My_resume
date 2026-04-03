#include <iostream>
#include <memory>
#include "Gadget.h"
#include "GadgetManager.h"

using namespace std;

int main() {
    cout << "=== Stack-based Gadget Operations ===" << endl;
    {
        // 스택에서 직접 Gadget 객체를 생성합니다.
        Gadget gadgetA("Alpha");

        // 복사 생성자 테스트
        Gadget gadgetB = gadgetA;  // "Gadget copied ..." 메시지 출력

        // 이동 생성자 테스트
        Gadget gadgetC("Beta");
        Gadget gadgetD = std::move(gadgetC);  // "Gadget moved ..." 메시지 출력

        cout << "\nDisplaying stack-based gadgets:" << endl;
        gadgetA.display();
        gadgetB.display();
        gadgetD.display();
    } // 이 블록이 끝나면 gadgetA, gadgetB, gadgetD 소멸 -> 소멸자 메시지 출력

    cout << "\nStack-based gadgets have been destroyed." << endl;

    cout << "\n=== Dynamic Gadget Operations & Inventory Check ===" << endl;
    // 동적 할당을 통한 Gadget 생성 (소멸은 shared_ptr의 참조 카운트에 따라 처리됨)
    auto dynGadget1 = make_shared<Gadget>("Gamma");
    auto dynGadget2 = make_shared<Gadget>("Delta");

    // 현재 GadgetManager의 인벤토리(정적 벡터)는 별도의 추가 API가 없으므로
    // 객체를 넣지 않은 상태입니다. (즉, getInventoryCount()는 0을 리턴할 것입니다.)
    cout << "Inventory Count: " << GadgetManager::getInventoryCount() << endl;

    // GadgetManager 객체를 생성한 후 인벤토리 내용을 출력합니다.
    GadgetManager manager;
    cout << "\nDisplaying inventory (expected none since no addition API exists):" << endl;
    manager.displayAll();

    cout << "\nDynamic gadgets will be destroyed as shared_ptrs go out of scope." << endl;

    return 0;
}
