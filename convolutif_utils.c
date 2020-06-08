#include "convolutif_utils.h"

mot init_mot() {
    mot M = (mot) malloc(sizeof(struct mot_t));
    M->l = 0;
    return M;
}

void grow_word(mot M, int length) {
    for (int i = 0; i < length; i++) {
        M->code[i + M->l] = '0';
    }
    M->l += length; //grow length
}

etat creer_etat() {

  etat tmp = (etat) malloc(sizeof(etat));
  tmp->trans_0 = NULL;
  tmp->trans_1 = NULL;
  return tmp;
}

etat init_automate(){
  etat e0 = creer_etat();
  etat e1 = creer_etat();
  etat e2 = creer_etat();
  etat e3 = creer_etat();
  e0->trans_0 = e0;
  e0->sortie_0[0] = '0';
  e0->sortie_0[1] = '0';

  e0->trans_1 = e2;
  e0->sortie_1[0] = '1';
  e0->sortie_1[1] = '1';

  e1->trans_0 = e0;
  e1->sortie_0[0] = '1';
  e1->sortie_0[1] = '1';

  e1->trans_1 = e2;
  e1->sortie_1[0] = '0';
  e1->sortie_1[1] = '0';

  e2->trans_0 = e1;
  e2->sortie_0[0] = '1';
  e2->sortie_0[1] = '0';

  e2->trans_1 = e3;
  e2->sortie_1[0] = '0';
  e2->sortie_1[1] = '1';

  e3->trans_0 = e1;
  e3->sortie_0[0] = '0';
  e3->sortie_0[1] = '1';

  e3->trans_1 = e3;
  e3->sortie_1[0] = '1';
  e3->sortie_1[1] = '0';

  return e0;

}
