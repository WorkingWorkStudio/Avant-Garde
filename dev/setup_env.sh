# put where you saved your VulkanSDK, for example:
export VULKAN_SDK=~/VulkanSDK/1.3.296.0/macOS
# ONLY MODIFY here^^^^^^^^^^^^^^^^^^^^^^^^^^^

# DON'T CHANGE
export PATH=$VULKAN_SDK/bin:$PATH
export DYLD_LIBRARY_PATH=$VULKAN_SDK/lib:$DYLD_LIBRARY_PATH
export VK_ICD_FILENAMES=$VULKAN_SDK/share/vulkan/icd.d/MoltenVK_icd.json
export VK_LAYER_PATH=$VULKAN_SDK/share/vulkan/explicit_layer.d