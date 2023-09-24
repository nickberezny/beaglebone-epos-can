/* Include files */

#include "controller_cgxe.h"
#include "m_ruThg8ilLzfH7h2KmGFzOE.h"

unsigned int cgxe_controller_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 2381794144 &&
      ssGetChecksum1(S) == 3574268267 &&
      ssGetChecksum2(S) == 2091662815 &&
      ssGetChecksum3(S) == 1800821273) {
    method_dispatcher_ruThg8ilLzfH7h2KmGFzOE(S, method, data);
    return 1;
  }

  return 0;
}
