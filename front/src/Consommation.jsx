import React, { useEffect, useState } from 'react';
import { fetchSimulatedEnergyData } from './donnees-simulees.js';

function Consommation() {
  const [data, setData] = useState({ edf: 0, solaire: 0 });
  const useSimulatedData = true; // bascule entre données réelles et simulées

  useEffect(() => {
    const fetchData = async () => {
      try {
        let result;
        if (useSimulatedData && window.fetchSimulatedEnergyData) {
          result = await window.fetchSimulatedEnergyData();
        } else {
          const response = await fetch('http://localhost:3001/api/consommation');
          result = await response.json();
        }
        // Harmoniser les noms des clés
        setData({
          edf: result.edf,
          solaire: result.solar || result.solaire || 0
        });
      } catch (error) {
        console.error('Erreur de récupération des données:', error);
      }
    };

    fetchData();
    const interval = setInterval(fetchData, 10000);
    return () => clearInterval(interval);
  }, []);

  return (
    <div>
      <h2>Consommation</h2>
      <div>
        <label>EDF (W): </label>
        <input type="text" readOnly value={data.edf} />
      </div>
      <div>
        <label>Solaire (W): </label>
        <input type="text" readOnly value={data.solaire} />
      </div>
    </div>
  );
}

export default Consommation;
