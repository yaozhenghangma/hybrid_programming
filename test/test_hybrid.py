import hybrid_example

def test():
    two_args = hybrid_example.c_vector(1.0, 2.0)
    assert len(two_args.vector) == 2
    assert two_args.function() == 1.0