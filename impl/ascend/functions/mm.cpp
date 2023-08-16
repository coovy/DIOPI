/**
 * @file
 * @author DeepLink
 * @copyright  (c) 2023, DeepLink.
 */

#include <diopi/functions.h>

#include "../common/acloprunner.hpp"

namespace impl {
namespace ascend {

extern "C" diopiError_t diopiMm(diopiContextHandle_t ctx, diopiTensorHandle_t out, diopiConstTensorHandle_t input, diopiConstTensorHandle_t mat2) {
    AclOpRunner<2, 1>("BatchMatMul", ctx).addInput(input, mat2).setAttr("adj_x1", true).setAttr("adj_x1", true).addOutput(out).run();
    return diopiSuccess;
}

}  // namespace ascend
}  // namespace impl