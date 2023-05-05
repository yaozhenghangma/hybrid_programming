import hybrid_example

a = hybrid_example.c_vector()
a.vector = [1.0, 2.0, 3.0]

def test_return():
    assert a.function() == 1.0