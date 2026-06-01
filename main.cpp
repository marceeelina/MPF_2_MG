def calfp(frates, fac_rate):
    # Function Units
    fun_units = [
        "External Inputs",
        "External Outputs",
        "External Inquiries",
        "Internal Logical Files",
        "External Interface Files"
    ]

    # Weight Rates
    wt_rates = ["Low", "Average", "High"]

    # Weight Factors
    wt_factors = [
        [3, 4, 6],       # EI
        [4, 5, 7],       # EO
        [3, 4, 6],       # EQ
        [7, 10, 15],     # ILF
        [5, 7, 10]       # EIF
    ]

    ufp = 0

    # Calculating UFP (Unadjusted Function Point)
    for i in range(5):
        for j in range(3):
            freq = frates[i][j]
            ufp += freq * wt_factors[i][j]

    # 14 factors
    aspects = [
        "reliable backup and recovery required ?",
        "data communication required ?",
        "are there distributed processing functions ?",
        "is performance critical ?",
        "will the system run in an existing heavily utilized operational environment ?",
        "on line data entry required ?",
        "does the on line data entry require the input transaction to be built over multiple screens or operations ?",
        "are the master files updated on line ?",
        "is the inputs, outputs, files or inquiries complex ?",
        "is the internal processing complex ?",
        "is the code designed to be reusable ?",
        "are the conversion and installation included in the design ?",
        "is the system designed for multiple installations in different organizations ?",
        "is the application designed to facilitate change and ease of use by the user ?"
    ]

    sum_f = 0

    # Taking Input of factors rate
    for i in range(14):
        rate = fac_rate
        sum_f += rate

    # Calculate CAF
    caf = 0.65 + 0.01 * sum_f

    # Calculate Function Point (FP)
    fp = ufp * caf

    # Output Values
    print("Function Point Analysis :-")
    print(f"Unadjusted Function Points (UFP) : {ufp}")
    print(f"Complexity Adjustment Factor (CAF) : {caf:.2f}")
    print(f"Function Points (FP) : {fp:.2f}")


# Główna funkcja z odpowiednio dobranymi wartościami
if __name__ == "__main__":
    frates = [
        [0, 0, 0], 
        [0, 2, 0],
        [1, 0, 0],  
        [0, 0, 10],
        [0, 0, 3] 
    ]


    fac_rate = 2

    calfp(frates, fac_rate)
