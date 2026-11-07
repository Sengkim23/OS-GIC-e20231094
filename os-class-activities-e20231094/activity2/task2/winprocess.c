
/* winprocess.c — Process creation on Windows using CreateProcess() */

#include <stdio.h>
#include <windows.h>

int main(void) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Initialize structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent process (PID: %lu) - creating child...\n",
        GetCurrentProcessId());

    // Path to Microsoft Paint
    char application[] = "C:\\Users\\cdc22\\AppData\\Local\\Microsoft\\WindowsApps\\mspaint.exe";

    // Create child process
    if (!CreateProcessA(
            application,    // Application path
            NULL,           // Command line
            NULL,           // Process security attributes
            NULL,           // Thread security attributes
            FALSE,          // Inherit handles
            0,              // Creation flags
            NULL,           // Environment
            NULL,           // Current directory
            &si,            // Startup information
            &pi             // Process information
        ))
    {
        fprintf(stderr, "CreateProcess failed! Error code: %lu\n",
                GetLastError());
        return 1;
    }

    // Display child process information
    printf("Child process created successfully!\n");
    printf("Child PID:       %lu\n", pi.dwProcessId);
    printf("Child Thread ID: %lu\n", pi.dwThreadId);

    printf("\nParent: waiting for child process to exit...\n");
    printf("Open Task Manager to observe the child process.\n");
    printf("Close Microsoft Paint to continue.\n");

    // Wait until child process terminates
    WaitForSingleObject(pi.hProcess, INFINITE);

    printf("\nParent: child process has exited.\n");

    // Release handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printf("Parent: resources cleaned up. Exiting.\n");

    return 0;
}
