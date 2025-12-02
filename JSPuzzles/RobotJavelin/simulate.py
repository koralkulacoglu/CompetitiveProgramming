import random
import math
from decimal import Decimal, getcontext

# Set global precision to 50 decimal places
getcontext().prec = 50

def simulate_robot_javelin(n_rounds=1_000_000):
    """
    Simulates the Robot Javelin game using high-precision Decimal arithmetic.
    
    Java-lin Strategy:
    - Knows Spears exploits the Nash Equilibrium threshold (k = 1/sqrt(2)).
    - If J1 > k (High Signal): Always Keep (mathematically optimal against Spears' 0.75 threshold).
    - If J1 <= k (Low Signal): Keep only if J1 > 7/12, otherwise re-throw.
    
    Spears Strategy:
    - If Signal High (J1 > k): Plays optimal against U[k, 1] -> Threshold 0.75.
    - If Signal Low (J1 <= k): Plays optimal against U[0, 1] -> Threshold 0.5.
    """
    
    javalin_wins = 0
    
    # Constants defined as Decimals for high precision
    # K_NASH = 1 / sqrt(2)
    K_NASH = Decimal(1) / Decimal(2).sqrt()
    
    # Derived Optimization Thresholds
    # JAVALIN_LOW_SIGNAL_KEEP_THRESHOLD = 7/12
    JAVALIN_LOW_SIGNAL_KEEP_THRESHOLD = Decimal(7) / Decimal(12)
    
    # Spears' thresholds
    SPEARS_THRESH_LOW_SIGNAL = Decimal('0.5')
    SPEARS_THRESH_HIGH_SIGNAL = Decimal('0.75')

    # Pre-calculate scale for random generation to avoid repeated power ops
    # 200 bits provides ~60 decimal digits of randomness, sufficient for 50-place precision
    random_bits = 200
    scale = Decimal(2**random_bits)

    for _ in range(n_rounds):
        # --- Java-lin's Turn ---
        # Generate random Decimal in [0, 1)
        j1 = Decimal(random.getrandbits(random_bits)) / scale
        
        # Determine the signal Spears receives (The Leak)
        signal_is_high = j1 > K_NASH
        
        j_final = Decimal(0)
        
        if signal_is_high:
            # Analysis shows Java-lin should always keep if J1 > K_NASH
            j_final = j1
        else:
            # Signal is low. Spears will use 0.5 threshold.
            # Java-lin keeps only if J1 > 7/12
            if j1 > JAVALIN_LOW_SIGNAL_KEEP_THRESHOLD:
                j_final = j1
            else:
                j_final = Decimal(random.getrandbits(random_bits)) / scale # Re-throw
        
        # --- Spears' Turn ---
        # Spears chooses threshold based on the signal
        s_threshold = SPEARS_THRESH_HIGH_SIGNAL if signal_is_high else SPEARS_THRESH_LOW_SIGNAL
        
        s1 = Decimal(random.getrandbits(random_bits)) / scale
        s_final = Decimal(0)
        
        if s1 > s_threshold:
            s_final = s1
        else:
            s_final = Decimal(random.getrandbits(random_bits)) / scale # Re-throw
            
        # --- Determine Winner ---
        if j_final > s_final:
            javalin_wins += 1
            
    return Decimal(javalin_wins) / Decimal(n_rounds)

if __name__ == "__main__":
    rounds = 1_000_000
    print(f"Simulating {rounds:,} rounds with High Precision (Decimal)...")
    
    win_rate = simulate_robot_javelin(rounds)
    
    # Exact Calculation: 163/192 - sqrt(2)/4
    # Using Decimal for high precision theoretical value
    exact_prob = (Decimal(163) / Decimal(192)) - (Decimal(2).sqrt() / Decimal(4))
    
    print("-" * 30)
    print(f"Simulated Win Rate: {win_rate:.20f}")
    print(f"Theoretical Exact:  {exact_prob:.20f}")
    print(f"Difference:         {abs(win_rate - exact_prob):.20f}")
    print("-" * 30)
