describe('bomb test cases', () => {
  function ascToWord(addresses = []) {
    return addresses.map(addr => String.fromCharCode(
      ...(addr
          .match(/(\w{2})/g)
          .filter(one => one !== '0x')
          .map(one => Number('0x' + one))
          .reverse()))
    ).join("")
  }

  it('phase2', () => {
    const ascs = [
      `0x25206425`,
      `0x64252064`,
      `0x20642520`,
      `0x25206425`,
      `0x0064`,
    ]

    expect(ascToWord(ascs)).toBe('%d %d %d %d %d %d')
  })

  it('phase1', () => {
    const ascs = [
      `0x64726f42`,
      `0x72207265`,
      `0x74616c65`,
      `0x736e6f69`,
      `0x74697720`,
      `0x61432068`,
      `0x6164616e`,
      `0x76616820`,
      `0x656e2065`,
      `0x20726576`,
      `0x6e656562`,
      `0x74656220`,
      `0x2e726574`,
    ]

    expect(ascToWord(ascs)).toBe('')
  })
})
