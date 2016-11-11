def isSafeLead(pointsAhead, hasBall, timeLeft):
  n = pointsAhead - 3;
  if hasBall:
      n += 0.5
  else:
      n -= 0.5
      if n < 0:
          n = 0
  result = n*n
  if result > timeLeft:
      return True
  else:
      return False

if __name__ == "__main__":
    print isSafeLead(1,True,20)
    print isSafeLead(5,True,40)
    print isSafeLead(5,True,6)
