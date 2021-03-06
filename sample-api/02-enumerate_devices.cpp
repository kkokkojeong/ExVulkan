#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vulkan/vulkan.h>

#define APP_SHORT_NAME "vulkansamples_instance"

int main(int argc, char *argv[]) {
//    struct sample_info info = {};
//    init_global_layer_properties(info);
//    init_instance(info, "vulkansamples_enumerate");
    // initialize the VkApplicationInfo structure
    VkApplicationInfo app_info = {};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pNext = NULL;
    app_info.pApplicationName = APP_SHORT_NAME;
    app_info.applicationVersion = 1;
    app_info.pEngineName = APP_SHORT_NAME;
    app_info.engineVersion = 1;
    app_info.apiVersion = VK_API_VERSION_1_0;

    // initialize the VkInstanceCreateInfo structure
    VkInstanceCreateInfo inst_info = {};
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    inst_info.pNext = NULL;
    inst_info.flags = 0;
    inst_info.pApplicationInfo = &app_info;
    inst_info.enabledExtensionCount = 0;
    inst_info.ppEnabledExtensionNames = NULL;
    inst_info.enabledLayerCount = 0;
    inst_info.ppEnabledLayerNames = NULL;

    VkInstance inst;
    VkResult res;

    res = vkCreateInstance(&inst_info, NULL, &inst);
    if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
        std::cout << "cannot find a compatible Vulkan ICD\n";
        exit(-1);
    } else if (res) {
        std::cout << "unknown error\n";
        exit(-1);
    }


    //
    // 물리적 장치 질의 - GPU
    //
    uint32_t gpu_count = 1;
    vkEnumeratePhysicalDevices(inst, &gpu_count, NULL);
    assert(gpu_count);
    std::cout << "gpu count : " << gpu_count << std::endl;

    /* VULKAN_KEY_END */

    vkDestroyInstance(inst, NULL);

    return 0;
}
