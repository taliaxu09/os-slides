stub = calculator_pb2_grpc.CalculatorStub(channel)
numbers = calculator_pb2.AddRequest(num1=num1, num2=num2)
response = stub.Add(numbers)
