#include "MultiLL.h"

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP->isidata.idGolongan = idGol;
    NP->isidata.namaGolongan = namaGol;
    NP->next = NP->prev = NULL;
    createListChild(NP->L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC->isidata.idHewan = idHwn;
    NC->isidata.namaHewan = namaHwn;
    NC->isidata.habitat = habitat;
    NC->isidata.ekor = tail;
    NC->isidata.bobot = weight;
    NC->next = NC->prev = NULL;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    if (NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild) {
    if (NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;
    NodeParent nodeHapus = LParent.first;
    if (LParent.first == LParent.last) {
        LParent.first = LParent.last = NULL;
    } else {
        LParent.first = LParent.first->next;
        LParent.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent) || NPrev == NULL) return;
    NodeParent nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }
    nodeHapus->next = NULL;
    if (!isEmptyChild(nodeHapus->L_Child)) {
        deleteListChild(nodeHapus->L_Child);
    }
    deallocNodeParent(nodeHapus);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;
    NodeChild nodeHapus = LChild.first;
    if (LChild.first == LChild.last) {
        LChild.first = LChild.last = NULL;
    } else {
        LChild.first = LChild.first->next;
        LChild.first->prev = NULL;
        nodeHapus->next = NULL;
    }
    deallocNodeChild(nodeHapus);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild) || NPrev == NULL) return;
    NodeChild nodeHapus = NPrev->next;
    if (nodeHapus == NULL) return;
    NPrev->next = nodeHapus->next;
    if (nodeHapus->next != NULL) {
        nodeHapus->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }
    nodeHapus->next = NULL;
    deallocNodeChild(nodeHapus);
}

void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
        return;
    }

    NodeParent np = LParent.first;
    int idxP = 1;
    while (np != NULL) {
        cout << "=== Parent " << idxP << " ===" << endl;
        cout << "ID Golongan : " << np->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << np->isidata.namaGolongan << endl;

        NodeChild nc = np->L_Child.first;
        if (nc == NULL) {
            cout << "  (tidak ada child)" << endl;
        } else {
            int idxC = 1;
            while (nc != NULL) {
                cout << "  - Child " << idxC << " :" << endl;
                cout << "      ID Hewan : " << nc->isidata.idHewan << endl;
                cout << "      Nama Hewan : " << nc->isidata.namaHewan << endl;
                cout << "      Habitat : " << nc->isidata.habitat << endl;
                cout << "      Ekor : " << (nc->isidata.ekor ? "True" : "False") << endl;
                cout << "      Bobot : " << nc->isidata.bobot << " kg" << endl;
                nc = nc->next;
                idxC++;
            }
        }
        cout << "---------------------------" << endl;
        np = np->next;
        idxP++;
    }
}

void deleteListChild(listChild &LChild) {
    NodeChild nodeBantu = LChild.first;
    while (nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}
