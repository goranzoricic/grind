#pragma once
struct GLFWwindow;

// One instance of this class exists for each window the aplication opens.
// Windows are created by the graphics API, since the setup requires API specific configuration.
class Window {

public:
    Window() : _dimWidth(0), _dimHeight(0), _wndWindow(nullptr) {};
    ~Window() {};

    // Set the window data
    void Initialize(uint32_t dimWidth, uint32_t dimHeight, GLFWwindow *wndWindow);

    // Should the window be closed?
    bool ShouldClose();
    // Process window messages.
    void ProcessMessages();
    // Close the window.
    void Close();

    // Get the handle to the underlying representation.
    struct GLFWwindow *GetHandle() const { return _wndWindow;  }

    // Get window width.
    uint32_t GetWidth() const { return _dimWidth; }
    // Get window height.
    uint32_t GetHeight() const { return _dimHeight; }
    // Make the window to update its dimensions from the underlying implementation.
    void UpdateDimensions();

private:
    // Window width and height.
    uint32_t _dimWidth;
    uint32_t _dimHeight;

    // GLFW window info
    struct GLFWwindow *_wndWindow;
};