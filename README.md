# 🔄 Push_swap

Sorting algorithm project developed as part of the 42 Common Core curriculum.

The goal of the project is to sort a stack of integers using two stacks and a limited set of operations while performing the minimum number of moves possible.

---

## 🚀 Features

<div>

<div style="float: right; margin-left: 20px;">
  <img align="right" src="https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExdzBxdHRmbnB6aWM5YXRvNDIwM3NjNXplbXo5ZjZkcXJxNHRhendiZSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/zNnCCjMQRUevJqyXbu/giphy.gif" width="280">
</div>

- Efficient integer sorting using stack operations  
- Input validation and error handling  
- Optimized solutions for small stacks  
- Cost-based sorting algorithm for large stacks  
- Bonus checker program to validate operations  
- XOR linked list implementation for memory efficiency  

</div>

---

## ⚙️ Available Operations

| Operation | Description |
|---|---|
| `sa` / `sb` | Swap first two elements |
| `pa` / `pb` | Push element between stacks |
| `ra` / `rb` | Rotate stack upward |
| `rra` / `rrb` | Reverse rotate stack |
| `ss` / `rr` / `rrr` | Combined operations |

---

## 🧠 Algorithm

### Small Stacks (2–5 numbers)
Uses optimized hardcoded solutions for minimal operations.

### Large Stacks (6+ numbers)
Uses a cost-based algorithm:
- Convert values into sorted indices
- Calculate cheapest moves
- Optimize rotations with `rr` and `rrr`
- Move elements efficiently between stacks

---

## 💻 Usage

### Compilation

```bash
make
make bonus
```

### Execution

```bash
./push_swap 3 2 1 6 5 8

# With checker
./push_swap 3 2 1 6 5 8 | ./checker 3 2 1 6 5 8
```

---

## 📚 What I Learned

- Sorting algorithms and optimization
- Stack manipulation
- Cost calculation strategies
- XOR linked lists
- Memory management in C
- Parsing and input validation
- Algorithm performance analysis

---


✅ Project completed successfully as part of my journey at 42.
