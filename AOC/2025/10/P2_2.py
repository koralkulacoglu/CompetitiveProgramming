import re
import sys
from z3 import *

def solve_machine_z3(buttons, targets):
    # Create an Optimizer instance
    opt = Optimize()
    
    # Create an integer variable for each button (how many times we press it)
    # x_0, x_1, x_2 ...
    press_counts = [Int(f'b_{i}') for i in range(len(buttons))]
    
    # 1. Constraint: Press counts must be non-negative
    for x in press_counts:
        opt.add(x >= 0)
        
    # 2. Constraint: For each counter index (0, 1, 2...), the sum of effects must equal target
    num_counters = len(targets)
    for col_idx in range(num_counters):
        # Gather all button variables that affect this specific counter index
        # If button 'i' affects 'col_idx', we add press_counts[i] to the sum
        button_contributions = []
        for btn_i, affected_indices in enumerate(buttons):
            if col_idx in affected_indices:
                button_contributions.append(press_counts[btn_i])
        
        # The sum of these button presses must exactly equal the target for this counter
        if button_contributions:
            opt.add(Sum(button_contributions) == targets[col_idx])
        else:
            # If no button affects this counter, but target is > 0, it's impossible.
            if targets[col_idx] > 0:
                return 0

    # 3. Objective: Minimize the total number of presses
    opt.minimize(Sum(press_counts))
    
    # 4. Solve
    if opt.check() == sat:
        model = opt.model()
        # Calculate total presses from the model
        total = sum(model[x].as_long() for x in press_counts)
        return total
    else:
        return 0

def solve_puzzle(input_text):
    total_presses = 0
    lines = input_text.strip().split('\n')
    
    for line in lines:
        if not line.strip(): continue
            
        # Parse Targets { ... }
        target_match = re.search(r'\{([\d,]+)\}', line)
        if not target_match: continue
        targets = [int(x) for x in target_match.group(1).split(',')]
        
        # Parse Buttons (...)
        button_matches = re.findall(r'\(([\d,]+)\)', line)
        buttons = []
        for b in button_matches:
            # Convert "1,3" into [1, 3]
            # Handle empty parens () just in case
            if not b.strip():
                buttons.append([])
            else:
                indices = [int(x) for x in b.split(',')]
                buttons.append(indices)
            
        total_presses += solve_machine_z3(buttons, targets)
        
    return total_presses

# --- PASTE YOUR INPUT BELOW ---
sample_data = """
[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}
[...#.] (0,2,3,4) (2,3) (0,4) (0,1,2) (1,2,3,4) {7,5,12,7,2}
[.###.#] (0,1,2,3,4) (0,3,4) (0,1,2,4,5) (1,2) {10,11,11,5,10,5}
"""

# If reading from file:
with open("input.txt") as f:
    data = f.read()
    print("Total:", solve_puzzle(data))

print("Total Minimum Presses:", solve_puzzle(sample_data))
