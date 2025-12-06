#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C_AV1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f);
    insertLastChild(P1->L_Child, C_AV1);
    NodeChild C_AV2 = allocNodeChild("AV002", "Bebek", "Air", true, 2.0f);
    insertLastChild(P1->L_Child, C_AV2);

    NodeChild C_M1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f);
    insertLastChild(P2->L_Child, C_M1);
    NodeChild C_M3 = allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f);
    insertLastChild(P2->L_Child, C_M3);
    NodeChild C_M2 = allocNodeChild("M002", "Kucing", "Darat", true, 4.0f);
    insertLastChild(P2->L_Child, C_M2);

    NodeChild C_AM1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f);
    insertLastChild(P4->L_Child, C_AM1);

    cout << "=== HASIL PRINT MLL STRUCTURE ===" << endl;
    printMLLStructure(LP);


    return 0;
}
