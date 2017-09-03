add_executable(imgui_glfw_opengl3 main.cpp imgui_impl_glfw_gl3.h imgui_impl_glfw_gl3.cpp)
target_link_libraries(imgui_glfw_opengl3
    PRIVATE
        ext::glew_static
		ext::glfw
		ext::imgui
)

# CMake scripts extensions
target_set_warnings(imgui_glfw_opengl3 ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Helper that can set default warning flags for you
target_enable_lto(imgui_glfw_opengl3 optimized) #enable lto if available for non-debug configurations
run_fixup(imgui_glfw_opengl3 "" "") # Copy dependencies next to the executable (DLLs for example)