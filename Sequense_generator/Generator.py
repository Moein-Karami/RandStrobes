import random 

def simulate_string(L, n, p ):

    start_copy = "".join([random.choice("ACGT") for i in range(L)])
    final_seq = [start_copy]
    for i in range(n): # loop over copies
        muts = set(random.sample(range(len(start_copy)),int(L*p))) # simulate L*p mutation positions (equivalent to saying mutation frequency p
        copy_with_mutations = "".join([start_copy[i] if i not in muts else random.choice(['', random.choice("ACGT"), start_copy[i] + random.choice("ACGT")]) for i in range(len(start_copy))])
        final_seq.append(copy_with_mutations)
        start_copy = copy_with_mutations

    final_seq = ''.join([copy for copy in final_seq])
    return final_seq

my_genome = simulate_string( 1000, 1000, 0.02 )

file = open("gen_mut_02_1000_1000", "w")
file.write(my_genome)
file.close()