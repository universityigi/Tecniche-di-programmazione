#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoAlbero alberoPiuDistanzaNodoR(TipoAlbero a,int livello) {
  if (estVuoto(a))
    return albBinVuoto();
  else
    return creaAlbBin(livello+(a->info),alberoPiuDistanzaNodoR(sinistro(a),livello+1),alberoPiuDistanzaNodoR(destro(a),livello+1));
}

TipoAlbero alberoPiuDistanzaNodo(TipoAlbero a) {
  return alberoPiuDistanzaNodoR(a,0);
}
