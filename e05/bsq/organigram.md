```

MAIN
 ├── no arguments → process_input(NULL) → stdin
 └── with arguments → process_input(file) → each file
         ↓
    process_input()
         ├── read_file() → Validation
         │     ├── Read parameters
         │     ├── Validate characters
         │     └── Read and validate map
         ├── solve_bsq() → iterate all cells
         │     ├── if cell empty -> curr_size = 1
         │     ├── check_size_exp() one-by-one until obs or boundary
         │     └── if new square bigger than old, update global maximum
         ├── print_map() → Print result
         ├── free_map_grid() → Free map->grid memory
         └── free(map) → Free map struct


