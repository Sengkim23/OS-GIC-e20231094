# Class Activity 4 — Shared File API

- **Student Name:** [LY SENGKIM]
- **Student ID:** [e20231094]
- **Partner Name:** [Partner Name]
- **Partner Student ID:** [Partner ID]
- **Server Machine Owner:** [Your Name or Partner Name]
- **Server IP Address:** [192.168.71.175]

---

## Task 1: C++ Before Mutex

![C++ before mutex](screenshots/cpp_before_mutex.png)

- Expected score after 20 total client requests:
- Actual score:
- What happened:

---

## Task 2: C++ After Mutex

![C++ after mutex](screenshots/cpp_after_mutex.png)

- Expected score after 20 total client requests:
- Actual score:
- What changed after adding mutex:

---

## Task 3: Java Before Synchronized

![Java before synchronized](screenshots/java_before_synchronized.png)

- Expected score after 20 total client requests:
- Actual score:
- What happened:

---

## Task 4: Java After Synchronized

![Java after synchronized](screenshots/java_after_synchronized.png)

- Expected score after 20 total client requests:
- Actual score:
- What changed after adding synchronized:

---

## Questions

1. Why should clients send requests to the server instead of writing the file directly?
2. Why does the server still have a race condition before mutex or synchronized?
3. In the C++ fixed version, what does `std::lock_guard<std::mutex>` protect?
4. In the Java fixed version, what does `synchronized` protect?
5. Why is the final score expected to be 20 when Student A sends 10 requests and Student B sends 10 requests?
6. What could happen if two separate servers update the same file at the same time?

---

## Reflection

_Compare the C++ and Java synchronization approaches. What did this activity teach you about protecting shared resources?_