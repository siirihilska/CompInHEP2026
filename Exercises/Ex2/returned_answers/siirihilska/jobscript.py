import subprocess

n = 10

processes = []

for i in range(1,n+1):
	file = open(f"pythonoutput_{i}.txt", "w")
	process = subprocess.Popen(["./hello", str(i)], stdout=file)
	processes.append((process, file))

for process, file in processes:
	process.wait()
	file.close()
