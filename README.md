# NETWORK LAB (S6)
# Questions

### Client Server Chat using TCP
Implement client-server communication using socket programming and TCP as
transport layer protocol.
### Client Server Chat using UDP
Implement client-server communication using socket programming and UDP as
transport layer protocol.
### Distance Vector Routing
Implementing Distance Vector Routing Algorithm
### File Transfer Protocol
Implemented file transfer protocol where we read a file name and reverse the contents stored in the file and store it to another file
### Leaky Bucket Algorithm
Implement congestion control using a leaky bucket algorithm.
### Matrix Multiplication using UDP
Implement matrix multiplication by reading matrix from client side, perform multiplication in server side and print it in the client side.
### Multi-Chat(TCP)
Implement Multi chat using TCP
### Odd-Even numbers using UDP
Implement Odd-Even by reading numbers from client side, find odd and even numbers from server side and print it in the client side.
### Prime-Composite using UDP
Implement Prime-Composite by reading numbers from client side, find prime and composite numbers from server side and print it in the client side.
### Sliding Window Protocols
Simulate sliding window flow control protocols.
<table>
<table border="1">
  <tr>
    <th colspan="4">Sliding Window Protocols</th>
  </tr>
  <tr>
    <td><strong>Stop and Wait</strong>->Sends one frame at a time and waits for an acknowledgment before sending the next. Simple but inefficient for long-distance communication.</td>
    <td><strong>Go-Back-N</strong>->Allows sending multiple frames before needing an acknowledgment, but if an error occurs, all frames from the error onward are retransmitted.</td>
    <td><strong>Selective Repeat</strong>->Sends multiple frames and retransmits only the specific frames that were lost or corrupted</td>
  </tr>
</table>
  
### Time Request
Implemented Time request

First run the server code after that run client code.

Here's how you can install **WSL (Windows Subsystem for Linux)** on a Windows 10 or Windows 11 machine:

---

### 🐧 **Install WSL via Command Line (Recommended for Windows 10/11)**

1. **Open PowerShell as Administrator**  
   - Search for **PowerShell** → Right-click → **Run as administrator**

2. **Run this command** to install WSL and the default Ubuntu distribution:
   ```powershell
   wsl --install
   ```

   > ⚠️ If you're on Windows 10 and this gives an error, try:
   ```powershell
   wsl --set-default-version 2
   ```
You're running into two main issues in your terminal:

---

### ✅ 1. **Installing packages**

Run the following to update your package lists and fix broken installs:

```bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install -f
```

If that doesn't work, try cleaning and updating again:

```bash
sudo apt-get clean
sudo apt-get update --fix-missing
```

---

### ✅ 2. **Command `cc` not found**

You're trying to compile a C file with `cc`, but `cc` (usually a symbolic link to GCC) is not installed yet.

#### ✅ Fix:

Install GCC:

```bash
sudo apt install gcc
```

Then you can compile your C file like this:

```bash
gcc server.c -o server
```
OR use
```bash
cc server.c
```

Then run it with:

```bash
./server
```
```bash
./a.out
```

---
