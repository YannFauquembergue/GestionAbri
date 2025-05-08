function getRandomFloat(min, max) {
  return parseFloat((Math.random() * (max - min) + min).toFixed(2));
}

// Simuler les données
function generateSimulatedData() {
  return {
      solar: getRandomFloat(2, 5),
      edf: getRandomFloat(1, 3)
  };
}

// Simuler une API locale via une fonction
window.fetchSimulatedEnergyData = function () {
  return new Promise((resolve) => {
      setTimeout(() => {
          resolve(generateSimulatedData());
      }, 500);
  });
};