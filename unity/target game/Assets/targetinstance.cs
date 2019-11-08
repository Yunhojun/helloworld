using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class targetinstance : MonoBehaviour
{
    public GameObject target;
    private float cycle = 0;
    public bool[] arr = new bool[35];

    // Start is called before the first frame update
    void Start()
    {
        for(int i=0; i<35; i++)
        {
            arr[i] = false;
        }
        target.GetComponent<targetScript>();
    }

    // Update is called once per frame
    void Update()
    {
        cycle += Time.deltaTime;
        if(cycle >= 1.0f)
        {
            randominstance();
            cycle = 0;
        }
        
    }

    public void randominstance()
    {
        while (true)
        {
            int x = Random.Range(-3, 4);
            int y = Random.Range(-2, 3);
            if (arr[(x+3) + ((y+2)*7)] == false)
            {
                Instantiate<GameObject>(target, new Vector3(x * 3, y * 3, 0), Quaternion.identity);
                arr[(x + 3) + ((y + 2) * 7)] = true;
                break;
            }
        }
    }
}//-9 , -6 -3 0 3 6 9 x 이렇게
//-6 -3 0 3 6 y
